n = int(input())

string = input().split(' ')

result = []

for i in range(n-1, -1, -1):
  if string[i] not in result:
    result.insert(0,string[i])

print(len(result))
print(' '.join(result))