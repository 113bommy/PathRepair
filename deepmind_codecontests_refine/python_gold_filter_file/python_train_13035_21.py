'''
5
5 2 3
1 2 3
4 3 3
4 1 2
10 2 6
1 2 3 4 5 7
2 1 1
2
100 76 8
76 75 36 67 41 74 10 77

'''
t = int(input())
for _ in range(t):
    n,s,k = map(int,input().split())
    a = list(map(int,input().split()))
    i = 0
    while  i<n :
        if s+i not in a and s+i <= n:
            print(i)
            break
        if s-i not in a and s-i > 0:
            print(i)
            break
        i+=1
