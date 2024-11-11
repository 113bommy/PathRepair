x, y = map(int, input().split())
n = int(input())
a = [x, y, y-x, -x, -y, x-y]
print(a[(n-1)%6] % 1000000007)