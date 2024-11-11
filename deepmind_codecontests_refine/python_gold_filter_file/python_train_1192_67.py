arr = "qwertyuiopasdfghjkl;zxcvbnm,./"



brr = [-1] * 256



for i in range(len(arr)) :

  brr[ord(arr[i])] = i

  

d = input()

st = input()



w = 0



if (d == "R") :

  w = -1

else :

  w = 1



for chars in st :

  print (arr[brr[ord(chars)]+w],end = "")