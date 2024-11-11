num_of_rooms = int(input(""))
for i in range(num_of_rooms):
    help_list = []
    num_of_seals = int(input(""))
    strong_of_seals = list(map(int, input().split()))
    for j in range(0,len(strong_of_seals)-1,2):
        help_list.append(strong_of_seals[j+1])
        help_list.append(strong_of_seals[j]*-1)    
    print(*help_list)