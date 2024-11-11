people, pack_count = map(int, input().split())
distressed = 0

for _ in range(people):
    take_or_give, ice_count = input().split()
    ice_count = int(ice_count)

    if take_or_give == '+':
        pack_count += ice_count
    elif ice_count <= pack_count:
        pack_count -= ice_count
    else:
        distressed += 1


print(pack_count, distressed)


