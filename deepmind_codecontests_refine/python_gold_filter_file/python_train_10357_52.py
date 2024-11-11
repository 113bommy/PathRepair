n, s = int(input()), 0
if n == 0:
  print("zero")
else:
    if n%10 == 1:
        s = "one"
    elif n%10  == 2:
        s = "two"
    elif n%10  == 3:
        s = "three"
    elif n%10  == 4:
        s = "four"
    elif n%10  == 5:
        s = "five"
    elif n%10  == 6:
        s = "six"
    elif n%10  == 7:
        s = "seven"
    elif n%10  == 8:
        s = "eight"
    elif n%10  == 9:
        s = "nine"
    if n < 10:
      print(s)
    elif n > 9 and n < 20:
        if n == 10:
            print("ten")
        elif n == 11:
            print("eleven")
        elif n == 12:
            print("twelve")
        elif n == 13:
            print("thirteen")
        elif n == 14:
            print("fourteen")
        elif n == 15:
            print("fifteen")
        elif n == 16:
            print("sixteen")
        elif n == 17:
            print("seventeen")
        elif n == 18:
            print("eighteen")
        elif n == 19:
            print("nineteen")
    else:
        if n // 10 == 2:
            f = "twenty"
        elif n // 10 == 3:
            f = "thirty"
        elif n // 10 == 4:
            f = "forty"
        elif n // 10 == 5:
            f = "fifty"
        elif n // 10 == 6:
            f = "sixty"
        elif n // 10 == 7:
            f = "seventy"
        elif n // 10 == 8:
            f = "eighty"
        elif n // 10 == 9:
            f = "ninety"
        if n%10==0:
            print(f)
        else:
            print(f+"-"+s)