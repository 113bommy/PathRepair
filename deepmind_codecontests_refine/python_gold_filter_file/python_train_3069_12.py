boardWeight = 0
pieceWeights = {"Q": 9, "R": 5, "B": 3, "N": 3, "P": 1, "K": 0, "q": -9, "r": -5, "b": -3, "n": -3, "p": -1, "k": 0, ".": 0}
for row in range(8):
    letters = input()
    for i in range(8):
        piece = letters[i]
        boardWeight += pieceWeights[piece]
if boardWeight > 0:
    print("White")
elif boardWeight < 0:
    print("Black")
else:
    print("Draw")
