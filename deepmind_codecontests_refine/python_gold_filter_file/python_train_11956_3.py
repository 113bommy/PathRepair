N = int(input())
K = int(input())
*A, = map(int, input().split())
print(sum([min(a,K-a)*2 for a in A]))