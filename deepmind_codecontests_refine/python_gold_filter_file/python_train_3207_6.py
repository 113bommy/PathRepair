s = input()
sa = s.replace('LR','L,R')
sb = sa.split(',')
ans = ''
for hoge in sb:
  poge = len(hoge)
  g = hoge.find('RL')
  if poge%2 == 0:
    r = poge//2
    l = poge//2
  else:
    if g%2 == 1:
      r = poge//2
      l = r + 1
    else:
      l = poge//2
      r = l + 1
  an = '0 '*(g)+str(r)+' '+str(l)+' 0'*(poge-g-2)+ ' '
  ans += an
print(ans)