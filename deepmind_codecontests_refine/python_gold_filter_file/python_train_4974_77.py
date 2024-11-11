d=int(input())
c=list(map(int,input().split()))


ss=[list(map(int,input().split())) for i in range(d)]

for i in range(d):
    print(i%26+1)