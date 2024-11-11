s=input()
s=s[:-1].strip()
if s[-1] in ("a","e","i","o","u","A","E","I","O","U","Y","y"):
    print("YES")
else:
    print("NO")