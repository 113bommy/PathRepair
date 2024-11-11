s=input()
t=input()
print(sum([1 for index,char in enumerate(s) if t[index]!=char])) 
 