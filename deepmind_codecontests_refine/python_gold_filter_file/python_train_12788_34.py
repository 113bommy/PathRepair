A, B, C, D, E, F = map(int, input().split())
ans_sw = 1
ans_s = 0
for a in range(F//(100*A)+1):
  for b in range(F//(100*B)+1):
    if 100*A*a + 100*B*b > F or 100*A*a+100*B*b == 0:
      continue
    for c in range((A*a+B*b)*E+1):
      for d in range((A*a+B*b)*E+1):
        sw = 100*A*a+100*B*b+C*c+D*d
        s = C*c+D*d
        if 0 < sw <= F and s <= (A*a+B*b)*E and ans_s/ans_sw < s/sw:
          ans_s = s
          ans_sw = sw
if ans_sw == 1:
  print(100*A ,0)
else:
  print(ans_sw, ans_s)
