N, A, B, C, D = map(int, input().split())
S = input()

if "##" in S[A:C] or "##" in S[B:D]:
  print("No")
  exit()

if D - C < 0:
  if "..." not in S[B-2:D+1]:
    print("No")
    exit()
    
print("Yes")