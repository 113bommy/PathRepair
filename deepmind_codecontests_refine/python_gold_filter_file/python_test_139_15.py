t = int(input())

for _ in range(0, t):
    
  string = input()

  if len(string) % 2 == 0 and string[0:int(len(string)/2)] == string[int(len(string)/2):]:
    print("YES")
  else:
    print("NO")