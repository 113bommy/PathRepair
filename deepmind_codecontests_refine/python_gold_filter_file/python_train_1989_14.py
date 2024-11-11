n = int(input())
new = int(input())
lavki = []

for number in range(n):
    lavki.append(int(input()))

maxi = max(lavki)+new
while new > 0 :
    for num in range(min(new,n)) :
        lavki[lavki.index(min(lavki))] = lavki[lavki.index(min(lavki))] + 1
        new = new - 1
        
print(max(lavki), maxi)