for e in iter(input,'0'):
 e=int(e)
 print(sum(e//5**i for i in range(1,7)))
