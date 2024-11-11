d = int(input())
n = int(input())
s = input()
temp = s.split()
days = [int(i) for i in temp]

result = 0

for i in range(0,n-1):
    result += (d - days[i])
print(result)
