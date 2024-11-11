T = int(input())
for z in range(T):
    N = int(input())
    lst1 = list(map(int, input().split()))
    flag = True
    for i in range(N-1):
        if abs(lst1[i] - lst1[i+1]) >= 2:
            print("YES")
            print(i+1, i+2)
            flag = False
            break
    if flag:
        print("NO")