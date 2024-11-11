s=input()
t=input()
i=0
o="Yes"
if(len(s)!=len(t)):
  o="No"
while(len(s)==len(t)and o=="Yes"and i<len(s)):
  if(s[i] == "a" or s[i] =="o" or s[i] =="i" or s[i] =="e" or s[i] =="u" )and (t[i] == "a" or t[i] =="o" or t[i] =="i" or t[i] =="e" or t[i] =="u"):
    o="Yes"
  elif(s[i] !=  "a" and s[i] !="o" and s[i] !="i" and s[i] !="e" and s[i] !="u" )and (t[i]!="a" and t[i]!="o" and t[i]!="i" and t[i]!="e" and t[i]!="u" ):
    o="Yes"
  else:
    o="No"
  i+=1 
print(o)  
     