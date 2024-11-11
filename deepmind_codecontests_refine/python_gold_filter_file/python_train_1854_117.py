A=input()
for i in range(3):
   if A[i]==A[i+1]:
      print("Bad")
      exit()
print("Good")