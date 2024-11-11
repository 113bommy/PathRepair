n = int(input())
x = 0
 
word = ""
for i in range(n):
    word = input()
    if word[1] == "+":
        x += 1
    else:
        x -= 1
        
print(x)