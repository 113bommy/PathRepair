N, A, B, C, D = map(int, input().split())
S = input()

if "##" in S[A:max(C,D)]:
  ans = "No"
elif C < D:
  ans = "Yes"
else:
  if "..." in S[B-2:D+1]:
    ans = "Yes"
  else:
    ans = "No"

print(ans)
