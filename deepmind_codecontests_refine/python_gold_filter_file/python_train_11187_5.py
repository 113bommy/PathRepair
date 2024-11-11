infinity = 10 ** 30

def find_extreme_towers(towers):
    min_tower, max_tower = 0, 0
    
    for tower in range(len(towers)):
        if towers[tower] < towers[min_tower]:
            min_tower = tower
        if towers[tower] > towers[max_tower]:
            max_tower = tower
            
    return min_tower, max_tower

def compute_instability(towers):
    min_tower, max_tower = find_extreme_towers(towers)
    return towers[max_tower] - towers[min_tower]
    
nb_towers, nb_operations = map(int, input().split())
towers = list(map(int, input().split()))
min_instability = compute_instability(towers)
operations = []
nb_operations_min = 0

for operation in range(nb_operations + 1):
    cur_instability = compute_instability(towers)

    if cur_instability < min_instability:
        min_instability = cur_instability
        nb_operations_min = operation
        
    if operation < nb_operations:
        min_tower, max_tower = find_extreme_towers(towers)
        operations.append((max_tower + 1, min_tower + 1))
        towers[min_tower] += 1
        towers[max_tower] -= 1
        
print(min_instability, nb_operations_min, sep = ' ')
for operation in range(nb_operations_min):
    print(operations[operation][0], operations[operation][1], sep = ' ')
