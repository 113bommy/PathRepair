s = input()

s = s.replace(' ','')

last = s[len(s) - 2].lower()

if last in ['a','e','i','o','u','y']:
    print("YES")
else:
    print("NO")