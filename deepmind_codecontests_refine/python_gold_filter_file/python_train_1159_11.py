n = int(input())
a = sorted(list(map(int, input().split())))
b = [a[i-1] for i in range(1, n+1) if i%2==1]
c = [a[i-1] for i in range(1, n+1) if i%2==0]
print(*(b+c[::-1]))