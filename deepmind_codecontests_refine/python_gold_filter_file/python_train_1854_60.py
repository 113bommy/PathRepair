s=input()
print("Bad" if any(s[i]==s[i+1] for i in range(3)) else "Good")