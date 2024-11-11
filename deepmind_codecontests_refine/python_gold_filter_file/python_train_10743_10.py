'''
3
4 4
1 1 1 1
3 1
1 2 3
3 3
1 2 3
'''

for _ in range(int(input())):
    n,m = map(int, input().split())
    a = list(map(int, input().split()))
    if m<n or n<=2:
        print (-1)
    else:
        print (2*sum(a)+(m-n)*min(a))
        for i in range(n-1):
            print (i+1, i+2)
        print (1,n)
        t = a.index(min(a))
        for i in range(m-n):
            print(t+2,t+1)