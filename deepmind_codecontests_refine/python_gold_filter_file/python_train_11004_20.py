def answer():
    a=int(input())
    return int(int(a/100)+int((a%100)/20)+int((a%20)/10)+int((a%10)/5)+a%5)
print(answer())