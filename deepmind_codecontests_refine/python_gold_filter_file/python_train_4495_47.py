s=input()
l=[ "A", "O", "Y", "E", "U", "I","a","o","y","e","u","i"]
for i in s:
                 if(i not in l):
                                  print(".",end="")
                                  print(i.lower(),end="")