t = int(input())
for _ in range(t):
    n = int(input())
    changing_list = list(map(int,input().split()))
    locking_list = list(map(int,input().split()))
    sort_list = []
    for i in range(n):
        if locking_list[i] == 0:
            sort_list.append(changing_list[i])
            changing_list[i] = "_"
    sort_list.sort()
    for j in range(n):
        if changing_list[j] == "_":
            changing_list[j] = sort_list[-1]
            sort_list.pop()
    print(*changing_list)