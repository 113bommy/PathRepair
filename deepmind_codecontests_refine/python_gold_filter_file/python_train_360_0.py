def equ(a,b) :
  if (a==b):
    return True
  la= len(a)
  lb= len(b)

  if ((la&1) or (lb&1)):
      return False

  if (la==1):
      return False
  as1 = a[0:la//2]
  as2 = a[la//2:la]
  bs1 = b[0:lb//2]
  bs2 = b[lb//2:lb]

  return (equ(as1,bs2) and equ(as2,bs1)) or (equ(as1,bs1) and equ(as2,bs2))


s1 = input()
s2 = input()

if(equ(s1,s2)):
    print("YES")
else:
    print("NO")