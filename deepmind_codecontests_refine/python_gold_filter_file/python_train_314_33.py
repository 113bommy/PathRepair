while(True):
  h,w=map(int,input().split())
  if h==0 and w==0:
    break
  rect=''
  for i in range(h):
    for j in range(w):
      if (i+j)%2  == 0:
        rect+='#'
      else:
        rect+='.'
    rect+='\n'
  print(rect)