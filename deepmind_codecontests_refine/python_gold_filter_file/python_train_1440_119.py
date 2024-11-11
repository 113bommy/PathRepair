N,X = map(int, input().split())
li = [int(input()) for i in range(N)]

print(N+(X-sum(li))//min(li))
