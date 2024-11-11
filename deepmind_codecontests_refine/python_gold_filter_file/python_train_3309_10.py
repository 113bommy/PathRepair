s,t = input().split()
A,B = map(int,input().split())
u = input()

if u==s:
    print(A-1,B)
else:
    print(A,B-1)