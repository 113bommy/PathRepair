#n = int(input()) 
n, m = map(int, input().split())
x = - 10 ** 11
for i in range(n):
    k, l = map(int, input().split()) 
    if l > m:
        x = max(x, k - (l - m))
    else:
        x = max(x, k)
print(x)
#s = input()
#c = list(map(int, input().split()))
