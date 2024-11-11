n=str(input())
print("Good" if all([n[i]!=n[i+1] for i in range(3)]) else "Bad")