

a = int(input())

#if (a >= 0):

for i in range(1, 17, 1):
    x = a + i
    aux = str(x)
    if aux.find('8') >= 0:
      sol = i
      break

#else:
#  sol = (a * -1) + 8

print(sol)