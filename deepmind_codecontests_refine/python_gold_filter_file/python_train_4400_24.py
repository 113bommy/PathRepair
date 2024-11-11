N = int(input())
K = list(map(int,input().split()))
for i in range (1,N+1):
    print(K.index(i)+1, end= " ")