def judge(t1, t2):
  if t1 < 35.5 and t2 < 71:
    print("AAA")
  elif t1 < 37.5 and t2 < 77:
    print("AA")
  elif t1 < 40 and t2 < 83:
    print("A")
  elif t1 < 43 and t2 < 89:
    print("B")
  elif t1 < 50 and t2 < 105:
    print("C")
  elif t1 < 55 and t2 < 116:
    print("D")
  elif t1 < 70 and t2 < 148:
    print ("E")
  else:
    print("NA")

while True:
  try:
   t1, t2 = map(float, input().split())
   judge(t1, t2)
  except EOFError:
    break
