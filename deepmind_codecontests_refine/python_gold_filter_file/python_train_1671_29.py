while True:
  h,w=map(int,input().split())
  if h==0 & w==0:
    break
  print("#" * w)
  for i in range(h-2):
    print("#"+"."*(w-2)+"#")
  print("#" * w)
  print()
