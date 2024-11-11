N = int(input())
S = input()
ans = 0

for pin in range(0,1000):
  counter = 0
  for index in range(0, N):
    if str(pin).zfill(3)[counter] == S[index]:
      counter += 1
    if counter == 3:
      ans += 1
      break
    
print(ans)