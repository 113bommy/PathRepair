n=input()
if any(n[i]==n[i+1] for i in range(0,3)):
    print("Bad")
else:
    print("Good")
