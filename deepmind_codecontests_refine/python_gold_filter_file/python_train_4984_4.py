for _ in[0]*int(input()):
 e=input()
 for i in range(26):
  for j in range(26):
   a=''.join([c,chr(((ord(c)-97)*i+j)%26+97)][c.islower()]for c in e)
   if'that'in a or'this'in a:print(a);break
