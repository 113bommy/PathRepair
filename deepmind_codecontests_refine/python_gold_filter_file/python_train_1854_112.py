s=input()
print("Good" if all(s[i]!=s[i+1]for i in range(3)) else "Bad")