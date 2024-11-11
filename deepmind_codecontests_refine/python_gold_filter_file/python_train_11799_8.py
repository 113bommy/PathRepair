n,t = map(int,input().split(' '))
mas = list()
t *= 2
suma = 2
for i in range(n):
  x,a = map(int,input().split(' '))
  mas.append(x*2-a)
  mas.append(x*2+a)
mas = sorted(mas)
for i in range(1,len(mas)//2):
  ras = mas[i*2]-mas[i*2-1]
  if ras>t:
    suma += 2
  elif ras==t:
    suma += 1
print(suma)