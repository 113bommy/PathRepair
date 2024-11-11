mydict={'q':9,'r':5,'b':3,'n':3,'p':1}
mydict2={'Q':9,'R':5,'B':3,'N':3,'P':1}
black_score=0;white_score=0
for i in range(8):
    string=input()
    for i in string:
        if i in mydict:
            black_score=black_score+mydict[i]
        elif i in mydict2:
            white_score=white_score+mydict2[i]
if black_score>white_score:
    print("Black")
elif white_score>black_score:
    print("White")
else:
    print("Draw")