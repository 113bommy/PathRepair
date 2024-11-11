n = int(input())
string = input().split(' ')

for i in range(n):
  string[i] = int(string[i])

Avotes = 0
Evotes = sum(string)
k = max(string) - 1

while Evotes >= Avotes:
  k += 1
  Avotes = 0
  for item in string:
    Avotes += k - item

print(k)