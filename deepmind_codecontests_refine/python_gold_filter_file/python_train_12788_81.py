a,b,c,d,e,f = map(int,input().split())
ans_per, ans_w, ans_s = -1,0,0
for i in range(f//(100*a) + 1):
  for j in range((f-100*i)//(100*b) + 1):
    if i == j == 0:
      continue
    w = i*a*100 + j*b*100
    r = min(f-w, w//100 * e)
    for x in range(r//c + 1):
      for y in range((r-x*c)//d + 1):
        s = x*c + y*d
        if s / w > ans_per:
          ans_per = s/w
          ans_w = w
          ans_s = s
print('{} {}'.format(ans_w+ans_s, ans_s))