n = int(input())
k = set("abcdefghijklmnopqrstuvwxyz")
end = False
ans = 0
for i in range(n):
 var = input().split()
 if not end:
  if var[0] == "!":
   k = set(var[1]) & k
  elif var[0] == ".":
   k = k - set(var[1])
  elif var[0] == "?":
   k = k - set(var[1])
  #print(k)
  if len(k) == 1:
   end = True
  continue
 if var[0] == "!":
  ans += 1
 if var[0] == "?":
  if i != n - 1:
   ans += 1
 #print("ans:",ans)
print(ans)