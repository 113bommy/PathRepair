w=input()
odd=[i for i in set(w) if w.count(i)%2]
print('No' if odd else 'Yes')