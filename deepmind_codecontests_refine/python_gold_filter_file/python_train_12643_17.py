x, y = [int(i) for i in input().split()]
n = int(input())

z= y-x

f = [x, y, z, -x, -y, -z]
print(f[(n-1)%6]%1000000007)