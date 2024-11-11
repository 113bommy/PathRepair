n=int(input())
def fun(n):
      s=str(n)
      for i in s:
            if(i!="1" and i!="4"):
                  return False
      if("444" in s):
            return False
      if(s[0]=="4"):
            return False
      return True
if(fun(n)):
      print("YES")
else:
      print("NO")            