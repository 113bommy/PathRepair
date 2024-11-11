for _ in range(int(input())):
  num = int(input())

  
  if 2 <= num <= 7:
    print(1)
  elif num % 2 == 0:
    print(num // 2)
  else:
    print(((num//2)-1)+1)