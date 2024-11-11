from fractions import Fraction

w, b = [int(x) for x in input().split()]

def probability(w, b):
    memory = {}

    def recursive(w, b):
        if w <= 0:
            return 0.0
        if b <= 0:
            return 1.0

        if (w, b) in memory:
            return memory[(w, b)]

        white = w
        black = b
        # princess turn
        # chance to win
        answer = white / (black + white)

        # chance to continue the game after choosing black mouse
        black -= 1
        cont_p = (1 - answer) * (black /(black + white))

        # it's too small to calc next
        if cont_p > 1e-13:
            # dragon chooses black mouse
            black -= 1
            # chance for white mouse pop out
            white_ch = white / (white + black)
            # win chances
            white_p = recursive(white - 1, black) * white_ch
            black_p = recursive(white, black - 1) * (1 - white_ch)
            answer += cont_p * (black_p + white_p)

        memory[(w, b)] = answer
        return answer
    
    return recursive(w, b)

answer = probability(w, b)
print(answer)