# Author: Josep Romagosa Llorden
# Contest: Semana i


def main():
  a, b = input().split()
  stepOne(int(a), int(b))


def stepOne(a, b):
  if (a == 0 or b == 0):
    print(a, b)
  else:
    if (checkValue(a, b)):
      a = changeValue(a, b)
      stepOne(a, b)
    elif (checkValue(b, a)):
      b = changeValue(b, a)
      stepOne(a, b)
    else:
      print(a, b)

def changeValue(num, num2):
    return num % (2*num2)


def checkValue(num, num2):
    if (num >= 2*num2):
      return 1
    return 0


main()
