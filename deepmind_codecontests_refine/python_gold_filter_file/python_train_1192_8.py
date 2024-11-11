KeyBoard = list("qwertyuiop[]asdfghjkl;'zxcvbnm,./")
Shift = input()
Sentence = input()
if Shift == "R":
    for i in Sentence:
        print(KeyBoard[KeyBoard.index(i) - 1], end="")
    exit()
for i in Sentence:
    print(KeyBoard[KeyBoard.index(i) + 1], end="")
