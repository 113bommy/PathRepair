n = int(input())
# n,m = map(int,input().split())
# s = input()
# m = [tuple(map(int,input().split())) for _ in range(n)]
# a = list(map(int,input().split()))
for i in range(9,0,-1):
        if n%i==0:
                print(n//i)
                a = [i]*(n//i)
                print(*a)
                break
