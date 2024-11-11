n = int(input()) + 1
f = list(map(int, input().split()))
arr = [1 + n*i for i in range(n*5)]
a = []
for i in range(1,6):
    if( i + sum(f) not in arr):
        a.append(i)
print(len(a))