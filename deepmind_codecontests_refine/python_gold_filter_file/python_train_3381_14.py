#codeforces_515A
L = [abs(int(e)) for e in input().split(" ")]
print(["No","Yes"][sum(L[:2])%2 == L[2]%2 and sum(L[:2]) <= L[2]])
